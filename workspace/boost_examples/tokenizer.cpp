std::string text = "Alice was beginning to get very tired of sitting by her sister on the "
                   "conversation?'";

using text_container = bmi::multi_index_container
                       <std::string, bmi::indexed_by<bmi::sequenced<>,
                                                     bmi::ordered_non_unique<bmi::identity<std::string>>>>;
text_container tc;
boost::tokenizer<boost::char_separator<char>> tok(text, boost::char_separator<char>(" \t\n.,;:!?'\"-"));
std::copy(tok.begin(), tok.end(), std::back_inserter(tc));

for (const auto& item : tc)
    std::cout << item << "\n";