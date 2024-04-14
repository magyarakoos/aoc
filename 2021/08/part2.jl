using Combinatorics
⊗ = [[1,1,1,0,1,1,1],[0,0,1,0,0,1,0],[1,0,1,1,1,0,1],[1,0,1,1,0,1,1],[0,1,1,1,0,1,0],[1,1,0,1,0,1,1],[1,1,0,1,1,1,1],[1,0,1,0,0,1,0],[1,1,1,1,1,1,1],[1,1,1,1,0,1,1]] 
f = map(l -> [split(match(r"(.*)\|(.*)", l)[i]) for i in 1:2], readlines("input"))
for (a, sol) in f
    for perm in permutations("abcdefg")
        taken = zeros(Char, 10)
        for s in a
            mask = zeros(Int, 7)
            for i in indexin(s, perm)
                mask[i] = 1
            end
        end
    end
end

