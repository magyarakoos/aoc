f = open("input", "r")
s = readline(f)
readline(f)
d = Dict{String, String}()
for l in eachline(f)
    d[l[1:2]] = l[7]
end