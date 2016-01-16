let combinations (s : string) =
  let c = s.ToCharArray() |> Array.sort
  let rec recurse i =
    if i = c.Length then
      Seq.empty
    else
      seq {
        yield string c.[i]
        for combination in recurse (i + 1) do
          yield string c.[i] + combination
        yield! recurse (i + 1)
      }
  recurse 0

let t = stdin.ReadLine() |> int
for _ in {1 .. t} do
  let n = stdin.ReadLine() |> int
  let s = stdin.ReadLine()
  combinations s |> Seq.iter (printfn "%s")
