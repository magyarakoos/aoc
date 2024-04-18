f = map(l -> map(m -> m, match(r".{6}(.[A-Z]).{15}(\d+).{24}\s+(.*)", l)), readlines("input"))
println(f)
