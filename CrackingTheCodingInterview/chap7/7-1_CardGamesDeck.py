"""
ブラックジャックのルールが分からなかったので
順番にカードをひいていって一番数字の合計が大きい人が勝ち
というルールにした
"""

from collections import namedtuple
from enum import Enum, IntEnum
import random

class Card:
    def __init__(self, suit, num):
        self.suit = CardSuit(suit)
        self.num = CardNum(num)


class CardSuit(Enum):
    CLUB = '♣︎'
    HEART = '❤︎'
    DIAMOND = '♦︎'
    SPADE = '♠︎'


class CardNum(IntEnum):
    ACE = 1
    TWO = 2
    THREE = 3
    FOUR = 4
    FIVE = 5
    SIX = 6
    SEVEN = 7
    EIGHT = 8
    NINE = 9
    TEN = 10
    JACK = 11
    QUEEN = 12
    KING = 13


class Deck:
    def __init__(self, card_list=None):
        self.card_list = []
        if card_list is None:
            # カード一覧
            for suit in CardSuit:
                for num in CardNum:
                    self.card_list.append(Card(suit, num))
        else:
            self.card_list = card_list


    def card_on_top(self):
        return self.card_list.pop()


    def shuffle(self):
        # シャッフル
        self.card_list = random.sample(self.card_list, len(self.card_list))
        return

class Player:
    def __init__(self, num, hand=None):
        if hand is None:
            self.hand = []
        else:
            self.hand = hand
        self.num = num

    def draw_card(self, deck: Deck):
        # カードを引く
        top = deck.card_list.pop()
        self.hand.append(top)
        return


    def report_score(self):
        # 点数を報告
        score = ScoreCalculator().calc(self.hand)
        return score


class ScoreCalculator:
    def calc(self, card_list):
        score = 0
        for card in card_list:
            score += card.num.value
        return score


class Game:
    def __init__(self, num_player):
        deck = Deck()
        deck.shuffle()
        self.deck = deck
        self.players = []
        for i in range(num_player):
            p = Player(i)
            self.players.append(p)


    def is_finished(self):
        return len(self.deck.card_list)==0


    def decide_winner(self):
        if not self.is_finished():
            return None
        max_score = 0
        max_player = -1
        score_map = {}
        for p in self.players:
            score = p.report_score()
            score_map[p.num] = score
            if score > max_score:
                max_score = score
                max_player = p
        print(max_player.num, "wins!")
        print("score一覧: ", score_map)
        return


    def run(self):
        while True:
            for p in self.players:
                if self.is_finished():
                    self.decide_winner()
                    return
                p.draw_card(self.deck)
        self.decide_winner()
        return



if __name__=='__main__':
    game = Game(5)
    game.run()
