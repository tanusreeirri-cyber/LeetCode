var minimumPushes = function(word) {
    const r = word.length % 8;
    const c = (word.length - r) / 8;
    return (4 * c + r) * (c + 1);
};