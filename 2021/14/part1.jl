f = open("input", "r")
s = readline(f); readline(f)
d = Dict{String, Char}()
map(l -> d[l[1:2]] = l[7], eachline(f))
for _ in 1:10
    t::String = s[1]
    for i in 2:length(s)
        if haskey(d, s[(i - 1):i])
            t = t + d[s[(i - 1):i]]
        end
        t = t + s[i]
    end
end
