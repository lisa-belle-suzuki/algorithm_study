class Solution:
    def subdomainVisits(self, cpdomains: List[str]) -> List[str]:
        domain_cnt = defaultdict(int)
        for item in cpdomains:
            cnt, domain = item.split(' ')
            cnt = int(cnt)
            subdomains = domain.split('.')
            for i in range(len(subdomains)):
                cur_domain = ".".join(subdomains[i:])
                domain_cnt[cur_domain] += cnt

        ret = []
        for k, v in domain_cnt.items():
            ret.append(str(v) + " " + k)
        return ret
