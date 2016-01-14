open System

let P = 1000000007L

module Matrix2x2 =
  type T = int64 * int64 * int64 * int64
  
  let identity : T = (1L, 0L, 0L, 1L)
  
  let multiply ((a, b, c, d) : T) ((a', b', c', d') : T) =
    (((a * a') % P + (b * c') % P) % P,
     ((a * b') % P + (b * d') % P) % P,
     ((c * a') % P + (d * c') % P) % P,
     ((c * b') % P + (d * d') % P) % P)

  let pow : T -> int -> T =
    let rec loop acc m k =
      if k = 0 then
        acc
      else if k % 2 = 0 then
        loop acc (multiply m m) (k / 2)
      else
        loop (multiply acc m) m (k - 1)
    loop identity

let t = Console.ReadLine() |> int

for _ in { 1 .. t } do
  match Console.ReadLine().Split(' ') |> Array.map int with
  | [|a; b; n|] ->
    let a = int64 a
    let b = int64 b
    let (x, _, _, _) = Matrix2x2.multiply (Matrix2x2.pow (1L, 1L, 1L, 0L) (n - 1)) (b, a, a, b - a)
    printfn "%d" x
  | _ ->
    failwith "Invalid input"
