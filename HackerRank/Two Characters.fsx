stdin.ReadLine() |> ignore
let s = stdin.ReadLine()
let mutable maxLength = 0
for c1 in 'a' .. 'z' do
  for c2 in char (int c1 + 1) .. 'z' do
    let rec loop i expected length =
      if i = s.Length then
        if length >= 2 then length else 0
      else
        match s.[i] with
        | c when c = c1 && expected <> 2 -> loop (i + 1) 2 (length + 1)
        | c when c = c1 && expected = 2 -> 0
        | c when c = c2 && expected <> 1 -> loop (i + 1) 1 (length + 1)
        | c when c = c2 && expected = 1 -> 0
        | _ -> loop (i + 1) expected length
    let length = loop 0 0 0
    if maxLength < length then
      maxLength <- length
printfn "%d" maxLength
