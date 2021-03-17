import math

hour, minute, H, M = map(int, input().split())
hour_angle = 30 * H + 0.5 * M
minute_angle = 6 * M
diff = abs(hour_angle - minute_angle)
diff = min(diff, 360 - diff)

print('{:.10f}'.format(math.sqrt(hour ** 2 + minute ** 2 - 2 *
                                 hour * minute * math.cos(math.pi * diff / 180))))
