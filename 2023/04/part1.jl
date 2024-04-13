f = open("input", "r")
rx = r"Card \d+: (\d+(?:\s+\d+)*) \| (\d+(?:\s+\d+)*)"
(a = []; b = [])
for l in eachline(f)
    push!(a, parse.(Int, split(match(rx, l)[1])))
    push!(b, parse.(Int, split(match(rx, l)[2])))
end
println(a)
println(b)