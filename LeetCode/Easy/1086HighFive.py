class Solution:
    def highFive(self, items: List[List[int]]) -> List[List[int]]:
        student_to_scores = defaultdict(list)
        for item in items:
            stu_id, score = item
            student_to_scores[stu_id].append(score)

        ans = []
        for stu_id in sorted(student_to_scores.keys()):
            scores = student_to_scores[stu_id]
            scores.sort(reverse=True)
            average = sum(scores[:5])//5
            ans.append([stu_id, average])

        return ans
