using Combinatorics
⊗ = [[1,1,1,0,1,1,1],[0,0,1,0,0,1,0],[1,0,1,1,1,0,1],[1,0,1,1,0,1,1],[0,1,1,1,0,1,0],[1,1,0,1,0,1,1],[1,1,0,1,1,1,1],[1,0,1,0,0,1,0],[1,1,1,1,1,1,1],[1,1,1,1,0,1,1]] 
f = map(l -> [split(match(r"(.*)\|(.*)", l)[i]) for i in 1:2], readlines("input"))
◿ = (a, perm) -> begin
    taken = fill("#", 10)
    for s in a
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
    return true
end
res = 0
for (a, sol) in f
    for perm in permutations("abcdefg")
        if (◿(a, perm))
            i = 0
            for s in sol
                mask = zeros(Int, 7)
                for j in indexin(s, perm)
                    mask[j] = 1
                end
                t = t + string(Char('0' + findfirst(x -> x == mask, ⊗)))
            end
            break
        end
    end
end