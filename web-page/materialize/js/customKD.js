//This file has been added by kedar

document.getElementById('biking').addEventListener('loadedmetadata', function () {
    this.currentTime = 6;
}, false);

var videoEnded = document.getElementById('biking');

videoEnded.onended =  function () {

    /*
        document.getElementById('div2').innerHTML = "<Ke></Ke>dar Did this " +
        "<br><br><br> sdkjncskjnkscnj<br><br><br>sdknjcknd";
    //document.getElementById('div2').src = 'loadInBikingPage.html';

    document.getElementById("div2").innerHTML='<object type="text/html" ' +
        'data="loadInBikingPage.html" ></object>';
     */
    document.getElementById("div2").style.visibility = "hidden";
    document.getElementById("div3").style.visibility = "initial";

    return false;
};

document.getElementById("img1").addEventListener('mouseover', function () {
    this.src = "k2.jpg"
});

document.getElementById("img1").addEventListener('mouseout', function () {
    this.src = "k1.jpg"
});

document.getElementById("div3").style.visibility = "hidden";
