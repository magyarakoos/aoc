using Combinatorics
⊗ = [[1,1,1,0,1,1,1],[0,0,1,0,0,1,0],[1,0,1,1,1,0,1],[1,0,1,1,0,1,1],[0,1,1,1,0,1,0],[1,1,0,1,0,1,1],[1,1,0,1,1,1,1],[1,0,1,0,0,1,0],[1,1,1,1,1,1,1],[1,1,1,1,0,1,1]] 
f = map(l -> [split(match(r"(.*)\|(.*)", l)[i]) for i in 1:2], readlines("input"))
◿ = (a, perm) -> begin
    
end
# for (a, sol) in f
#     for perm in permutations("abcdefg")
#         taken = zeros(Char, 10)
#         for s in a
#             mask = zeros(Int, 7)
#             for i in indexin(s, perm)
#                 mask[i] = 1
#             end
#         end
#     end
# end

perm = ['d','e','a','f','g','b','c']
perm = ['a','b','c','d','e','f','g']
taken = fill("#", 10)
for s in f[1][1]
    mask = zeros(Int, 7)
    for i in indexin(s, perm)
        mask[i] = 1
    end
    if (!∈(mask, ⊗))
        return false
    end
    n = findfirst(x -> x == mask, ⊗)
    if taken[n] == "#"
        taken[n] = s
    else
        if taken[n] != s
            return false
        end
    end
end