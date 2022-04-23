class Solution {
public:
    unordered_map<string, string>UrlToCode, codeToUrl;
    string alphanumeric, base;    
	
    Solution(): base("https://tinyurl.com/"),
    alphanumeric("abcdefghijklmnopqrstuvwxyzAbCDEFGHIJKLMNOPQRSTUVWXYZ0123456789") {
        srand(time(0)); 
    }
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        
        if(UrlToCode.count(longUrl)) return base + UrlToCode[longUrl];
        string code = "";
        
        while(1){
            for(int i = 0; i < 6; i++)
                code += alphanumeric[rand() % 62];
            
            if(!codeToUrl.count(code)) break; 
            code = "";   
        }
        string encoded = base + code;
        UrlToCode[longUrl] = code;          
        codeToUrl[encoded] = longUrl; 
        return encoded;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return codeToUrl[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));