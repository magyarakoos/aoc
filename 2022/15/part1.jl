∆(a, b) = abs(a[1] - b[1]) + abs(a[2] - b[2])
const rx = r".{12}(-?\d+).{4}(-?\d+).{25}(-?\d+).{4}(-?\d+)"
const y::Int = 10
intvs = []; beacons = []
for l in eachline(open("input", "r"))
    m = [parse.(Int, match(rx, l)[i]) for i in 1:4]
    ps = (m[1], m[2]); pb = (m[3], m[4])
    if pb[2] == y
        push!(beacons, )
    d = ∆(ps, pb); h = ∆(ps, (ps[1], y))

end