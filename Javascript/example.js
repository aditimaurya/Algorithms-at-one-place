var maxLength = function(arr) {
  let max = 0;
  backtrack([], arr, 0);
  return max;

  function backtrack(tmp, n, start) {
    const w = tmp.join('');
    if (isUnique(w)) {
      max = Math.max(max, w.length);
    }

    for (let i = start; i < n.length; i++) {
      tmp.push(n[i]);
      backtrack(tmp, n, i + 1); // make sure it's `i`, I always make mistake by putting `start`
      tmp.pop();
    }
  }
};

function isUnique (s) {
  return s.length === new Set(s.split('')).size;
}
