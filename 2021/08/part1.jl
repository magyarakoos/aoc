f = map(l -> match(r".*\|(.*)", l), readlines("input"))
println(f)