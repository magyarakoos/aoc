using Combinatorics
f = map(l -> [match(r"(.*)\|(.*)", l)[i] for i in 1:2], readlines("input"))

println(f)