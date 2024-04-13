using IntervalSets
∆(a, b) = abs(a[1] - b[1]) + abs(a[2] - b[2])
∩(a, b) = !isempty(intersect(Interval(a[1], a[2]), Interval(b[1], b[2])))
const rx = r".{12}(-?\d+).{4}(-?\d+).{25}(-?\d+).{4}(-?\d+)"
const y::Int = 10
intvs = Set(); beacons = Set(); beacons2 = Set()

for l in eachline(open("input", "r"))
    m = [parse.(Int, match(rx, l)[i]) for i in 1:4]
    ps = (m[1], m[2]); pb = (m[3], m[4])
    if pb[2] == y
        push!(beacons, pb[1])
    end
    d = ∆(ps, pb) - ∆(ps, (ps[1], y))
    if (d >= 0)
        push!(intvs, (ps[1] - d, ps[1] + d))
    end
end

for (b, e) in intvs, x in beacons
    if b <= x && x <= e
        push!(beacons2, x)
    end
end

intvs2 = []
for intv in intvs
    i = 1
    while i <= length(intvs2)
        if ∩(intvs2[i], intv)
            println((intvs2[i], intv))
            intvs2[i] = (min(intvs2[i][1], intv[1]), max(intvs2[i][2], intv[2]))
            break
        end
        i += 1
    end
    if i > length(intvs2)
        push!(intvs2, intv)
    end
end

println(intvs2)