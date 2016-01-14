open System

let m = 100000L

let t = Console.ReadLine() |> int

for _ in { 1 .. t } do
  let n = Console.ReadLine() |> int
  let rec pow2mod m n =
    if n = 0 then
      1L
    else if n % 2 = 0 then
      let r = pow2mod m (n / 2)
      (r * r) % m
    else
      (2L * pow2mod m (n - 1)) % m
  printfn "%d" ((pow2mod m n + m - 1L) % m)
