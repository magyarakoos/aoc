println(count(s -> in(length(s), [2, 3, 4, 7]), split(join(map(l -> match(r".*\|(.*)", l)[1], readlines("input")), " "))))
