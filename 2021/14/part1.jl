using StatsBase
f = open("input", "r")
s = readline(f); readline(f)
d = Dict{String, Char}()
map(l -> d[l[1:2]] = l[7], eachline(f))
for _ in 1:10
    t = s[1]
    for i in eachindex(s)
        if i > 1
            if haskey(d, s[i - 1:i])
                t *= d[s[i - 1:i]]
            end
            t *= s[i]
        end
    end
    global s = t
end
println(sort(collect(values(countmap(s)))))