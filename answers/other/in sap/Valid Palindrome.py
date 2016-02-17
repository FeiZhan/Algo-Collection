class Solution(object):
	def isPalindrome(self, s):
		"""
		:type s: str
		:rtype: bool
		"""
		
		left = 0
		right = len(s) - 1
		while left < right:
			left_flag = s[left].isalnum()
			right_flag = s[right].isalnum()
			if left_flag and right_flag:
				if s[left].lower() != s[right].lower():
					return False
				left += 1
				right -= 1
			if not left_flag:
				left += 1
			if not right_flag:
				right -= 1
		return True