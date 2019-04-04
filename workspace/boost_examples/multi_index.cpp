auto [it, end] = accessByKey.equal_range(keyToFind);
while (it != end)
{
   ++it;
}

auto it = accessByKey.find(keyToFind);
if (it == accessByKey.end())
   util::Print("not found");