using DataStructures
using Statistics
d = Dict('('=>')', '['=>']', '{'=>'}', '<'=>'>')
v = Dict(')'=>3, ']'=>57, '}'=>1197, '>'=>25137)
v2 = Dict('('=>1, '['=>2, '{'=>3, '<'=>4)
p1 = 0; p2 = []
for l in readlines("input")
    s = Stack{Char}(); corrupt = false
    for c in l
        if c ∈ keys(d) push!(s, c)
        elseif c != d[first(s)]
            global p1 += v[c]
            corrupt = true
            break
        else pop!(s) end
    end
    if !corrupt && length(s) > 0
        score = 0
        while length(s) > 0
            score = score * 5 + v2[first(s)]
            pop!(s)
        end
        push!(p2, score)
    end
end
println("$p1\n$(Int(median(p2)))")
