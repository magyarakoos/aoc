open("input") do f
    m = match(r"/.{12}(-?\d+).{4}(-?\d+).{25}(-?\d+).{4}(-?\d+)/gm", readline(f))
    p1 = (m[1], m[2])
end