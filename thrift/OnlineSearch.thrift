namespace cpp OnlineSearch.Interface

typedef i32 SearchId

enum SearchStatus
{
    Searching,
    Done,
}

struct SearchResult
{
    1:string _name
}

struct ConnectionInfo
{
    1:string _address,
    2:i32 _port,
    3:string _client_id
}

service OnlineSearchProxy
{
    void onSearchStatusChanged(1:SearchId search_id, 2:SearchStatus search_status),
    void onSearchResultChanged(1:SearchId search_id, 2:list<SearchResult> results)
}

service OnlineSearch
{
    bool connect(),
    SearchId search(1:string input)
}