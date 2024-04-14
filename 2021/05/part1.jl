m = zeros(Int, 1000, 1000)
map(l -> map(x -> (x[1], x[2], x[3], x[4]), match(r"(\d+),(\d+) -> (\d+),(\d+)", l)), readlines("input"))