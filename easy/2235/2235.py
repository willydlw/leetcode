class Solution:
    def sum(self, num1: int, num2: int) -> int:
        return num1 + num2
    
def test(num1: int, num2: int, expected: int):
    s = Solution()
    result = s.sum(num1, num2)
    assert result == expected

def run_tests():
    test(12, 5, 17)
    test(-10, 4, -6)
    test(-100, 100, 0)

def main():
    run_tests()


if __name__ == "__main__":
    main()