class Codec:
    def __init__(self):
        self.original2tiny = {}
        self.tiny2original = {}
        self.cnt = 0

    def encode(self, longUrl: str) -> str:
        """Encodes a URL to a shortened URL.
        """
        ret = "http://tinyurl.com/"
        ret += str(self.cnt)
        self.cnt += 1
        self.original2tiny[longUrl] = str(self.cnt)
        self.tiny2original[ret] = longUrl
        return ret

    def decode(self, shortUrl: str) -> str:
        """Decodes a shortened URL to its original URL.
        """
        return self.tiny2original[shortUrl]


# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.decode(codec.encode(url))
