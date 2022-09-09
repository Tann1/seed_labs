#!/bin/env python3

import random

s = "abcdefghijklmnopqrstuvwxyz"
lst = random.sample(s, len(s))
key = ''.join(lst)
print(key)
