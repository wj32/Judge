open System

let nextLex (s : string) =
  let rec swappable i =
    if i > 0 then
      if s.[i - 1] < s.[i] then
        Some (i - 1)
      else
        swappable (i - 1)
    else
      None
  let rec lastGreaterThan maxIndex i c =
    if i >= s.Length then
      maxIndex
    else
      lastGreaterThan (if s.[i] > c then i else maxIndex) (i + 1) c
  match swappable (s.Length - 1) with
  | Some i ->
    let j = lastGreaterThan (i + 1) (i + 1) s.[i]
    Some
      (s.Substring(0, i)
       + string s.[j]
       + String([s.Substring(i + 1, j - i - 1); string s.[i]; s.Substring(j + 1)]
                |> Seq.concat
                |> Seq.toArray
                |> Array.rev))
  | None ->
    None

let n = Console.ReadLine() |> int

for _ in 1 .. n do
  match nextLex (Console.ReadLine()) with
  | Some s -> printfn "%s" s
  | None -> printfn "no answer"
