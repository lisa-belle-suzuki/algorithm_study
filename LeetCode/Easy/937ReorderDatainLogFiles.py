class Solution:
    def reorderLogFiles(self, logs: List[str]) -> List[str]:
        letter_log_to_original = defaultdict(list)
        digit_logs = []
        letter_logs = []
        for log in logs:
            log_list = log.split(' ')
            if log_list[1].isdecimal():
                digit_logs.append(log)
            else:
                letter_log = ''.join(log_list[1:])
                letter_log_to_original[letter_log].append(log)
                letter_logs.append(log_list[1:])
        letter_logs.sort()
        i = 0
        while i < len(letter_logs):
            log = letter_logs[i]
            originals = letter_log_to_original["".join(log)]
            originals.sort()
            for j in range(len(originals)):
                letter_logs[i+j] = originals[j]
            i += len(originals)

        return letter_logs + digit_logs
