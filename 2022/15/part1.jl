∆(a, b) = abs(a[1] - b[1]) + abs(a[2] - b[2])
rx = r".{12}(-?\d+).{4}(-?\d+).{25}(-?\d+).{4}(-?\d+)"

for l in eachline(open("input", "r"))
    m = [parse.(Int, match(rx, l)[i]) for i in 1:4]
    ps = (m[1], m[2]); pb = (m[3], m[4])
    println(∆(ps, pb))
    
end