f = open("input", "r")
s = readline(f)
readline(f)
d = Dict{String, Char}()
for l in eachline(f)
    d[l[1:2]] = l[7]
end
map(l -> )
println(d)