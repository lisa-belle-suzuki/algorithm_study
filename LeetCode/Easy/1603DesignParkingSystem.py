class ParkingSystem:

    def __init__(self, big: int, medium: int, small: int):
        self.big_size = big
        self.big_cnt = 0
        self.med_size = medium
        self.med_cnt = 0
        self.sml_size = small
        self.sml_cnt = 0

    def addCar(self, carType: int) -> bool:
        if carType == 1:
            if self.big_cnt == self.big_size:
                return False
            self.big_cnt += 1
            return True
        if carType == 2:
            if self.med_cnt == self.med_size:
                return False
            self.med_cnt += 1
            return True
        if carType == 3:
            if self.sml_cnt == self.sml_size:
                return False
            self.sml_cnt += 1
            return True


# Your ParkingSystem object will be instantiated and called as such:
# obj = ParkingSystem(big, medium, small)
# param_1 = obj.addCar(carType)
