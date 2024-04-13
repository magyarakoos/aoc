f = open("input", "r")
rx = r"Card \d+: (\d+(?:\s+\d+)*) \| (\d+(?:\s+\d+)*)"
(a = []; b = [])
for l in eachline(f)
    a = parse.(Int, split(match(rx, l)[1]))
    b = 
    push!(a, )
    push!(b, parse.(Int, split(match(rx, l)[2])))
end
