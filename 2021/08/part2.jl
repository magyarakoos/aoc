using Combinatorics
for (a, sol) in map(l -> [split(match(r"(.*)\|(.*)", l)[i]) for i in 1:2], readlines("input"))

end