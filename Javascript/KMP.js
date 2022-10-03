<script>
    function computeLPSArray(pat, M, lps)
    {
        var len = 0;
        var i = 1;
        lps[0] = 0; // lps[0] is always 0
     
        while (i < M) {
            if (pat.charAt(i) == pat.charAt(len)) {
                len++;
                lps[i] = len;
                i++;
            }
            else
            {
                if (len != 0) {
                    len = lps[len - 1];
     
                }
                else // if (len == 0)
                {
                    lps[i] = len;
                    i++;
                }
            }
        }
    }
     
    function KMPSearch(pat,txt)
    {
        var M = pat.length;
        var N = txt.length;
     
        var lps = [];
        var j = 0;
        computeLPSArray(pat, M, lps);
     
        var i = 0; // index for txt[]
        while ((N - i) >= (M - j)) {
            if (pat.charAt(j) == txt.charAt(i)) {
                j++;
                i++;
            }
            if (j == M) {
                document.write("Found pattern " + "at index " + (i - j) + "\n");
                j = lps[j - 1];
            }
            else if (i < N && pat.charAt(j) != txt.charAt(i)) {
                if (j != 0)
                    j = lps[j - 1];
                else
                    i = i + 1;
            }
        }
    }
     
     
    var txt = "ABABDABACDABABCABAB";
    var pat = "ABABCABAB";
    KMPSearch(pat, txt);
</script>