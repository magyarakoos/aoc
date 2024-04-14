using Combinatorics
⊗ = (d) -> ∈(d, [[1,1,1,0,1,1,1],[0,0,1,0,0,1,0],[1,0,1,1,1,0,1],[1,0,1,1,0,1,1],[0,1,1,1,0,1,0],[1,1,0,1,0,1,1],[1,1,0,1,1,1,1],[1,0,1,0,0,1,0],[]])
f = map(l -> [split(match(r"(.*)\|(.*)", l)[i]) for i in 1:2], readlines("input"))
for (a, sol) in f
    for perm in permutations("abcdefg")
        
    end
    println(a)
end

