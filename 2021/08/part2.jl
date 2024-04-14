using Combinatorics
f = map(l -> [split(match(r"(.*)\|(.*)", l)[i]) for i in 1:2], readlines("input"))
for (a, sol) in f 

end