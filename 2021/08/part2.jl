using Combinatorics
f = map(l -> match(r"(.*)\|(.*)", l)[1:2], readlines("input"))

println(f)