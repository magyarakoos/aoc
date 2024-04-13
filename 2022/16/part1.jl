f = map(l -> match(r".{6}(\w+).{15}(\d+).{23}\w?\s(.*)", l), 
    readlines("input"))

g = 