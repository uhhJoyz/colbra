# utils/timer.py
import time

def measure_time(func, synchronize=None, trials=10, warmups=2):
    for _ in range(warmups):
        func()
        if synchronize:
            try:
                synchronize()
            except Exception:
                pass

    times = []
    for _ in range(trials):
        t0 = time.perf_counter()
        func()
        if synchronize:
            try:
                synchronize()
            except Exception:
                pass
        t1 = time.perf_counter()
        times.append((t1 - t0) * 1000.0)

    mean = sum(times) / len(times)
    std = (sum((x - mean) ** 2 for x in times) / len(times)) ** 0.5
    return mean, std
