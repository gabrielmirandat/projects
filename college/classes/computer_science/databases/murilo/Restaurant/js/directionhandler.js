var direction = function(){

    var directionsDisplay;
    var directionsService = new google.maps.DirectionsService();
    var map;
    
    function initialize() {
        directionsDisplay = new google.maps.DirectionsRenderer();
        var myLatLng = new google.maps.LatLng(33.20770718,-97.152652);
        var mapOptions = {
            zoom: 16,
            center: myLatLng
        };

        map = new google.maps.Map(document.getElementById('map'), mapOptions);

        var marker = new google.maps.Marker({
            position: myLatLng,
            map: map,
            title: 'Sushimi Restaurant'
        });

        directionsDisplay.setMap(map);

    }

    function calcRoute() {
        var start = document.getElementById("start").value;
        var end = myLatLng;
        var request = {
            origin:start,
            destination:end,
            travelMode: google.maps.TravelMode.DRIVING
        };
        directionsService.route(request, function(response, status) {
            if (status == google.maps.DirectionsStatus.OK) {
                directionsDisplay.setDirections(response);
            }
        });
    }

    function loadScript() {
        var script = document.createElement('script');
        script.type = 'text/javascript';
        script.src = 'https://maps.googleapis.com/maps/api/js?v=3.exp'+'&signed_in=true&callback=initialize';
        document.body.appendChild(script);
    }

    window.onload = loadScript;
}

$(document).ready(direction);