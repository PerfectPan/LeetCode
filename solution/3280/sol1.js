/**
 * @param {string} date
 * @return {string}
 */
var convertDateToBinary = function(date) {
    return date.split('-').map((v) => Number(v).toString(2)).join('-');
};
