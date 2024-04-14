f = open("input", "r")
a = []
for l in eachline(f)
    x = 0
    for i in eachindex(l)
        x |= (s[i] == '1')
    end
end