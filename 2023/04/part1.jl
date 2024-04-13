f = open("input", "r")
rx = r"Card \d+: ((?:\d+\s+)+)\| ((?:\d+\s+)+)"
(a = []; b = [])
for l in eachline(f)
    push!(a, rx.captures[1])
    push!(b, rx.captures[2])
end
