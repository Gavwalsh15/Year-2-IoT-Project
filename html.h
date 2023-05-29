String MainPage = R"======(
<!DOCTYPE html>
<html lang="EN">
<head>
<meta name="viewport" content="width=device-width, initial-scale=1.0">
<style>
      
    body {
      background-image: url('https://art.pixilart.com/sr29d57691e4144.gif');
      background-repeat: repeat;
      background-size: cover;
      background-position: center;

      font-family: Arial, sans-serif;
      height: 100vh;
      margin: 0;
      padding: 10px;
    }

    h1 {
      font-size: 40px;
      color: #444;
      margin-bottom: 14px;
      text-align: center;
    }

    p {
      font-size: 24px;
      color: #333;
      margin-bottom: 10px;
      text-align: left;
      margin-left: 10px;
    }

    .slidecontainer {
      margin-top: 24px;
      display: flex;
      flex-direction: column;
      align-items: left;
      justify-content: left;
      padding: 14px;
      width: 100%;
      max-width: 380px;
    }
        
        .bt {
      display: flex;
      flex-direction: column;
      align-items: left;
      justify-content: left;
      padding: 14px;
      width: 100%;
      max-width: 380px;
      }
    
    .slider {
      -webkit-appearance: none;
      width: 100%;
      max-width: 500px;
      height: 15px;
      border-radius: 5px;
      background: #9ad9e4;
      outline: none;
      opacity: 0.7;
      -webkit-transition: .2s;
      transition: opacity .2s;
      box-shadow: 0px 4px 4px rgba(0, 0, 0, 0.25);
    }

    .slider:hover {
      opacity: 1;
    }

    .slider::-webkit-slider-thumb {
      -webkit-appearance: none;
      appearance: none;
      width: 20px;
      height: 20px;
      border-radius: 50%;
      background: #566ef6;
      cursor: pointer;
    }

    .slider::-moz-range-thumb {
      width: 20px;
      height: 20px;
      border-radius: 50%;
      background: #566ef6;
      cursor: pointer;
    }

    .button {
      position: relative;
      background-color: #566ef6;
      border: none;
      font-size: 28px;
      color: #FFFFFF;
      padding: 20px;
      width: 100%;
      max-width: 600px;
      text-align: center;
      transition-duration: 0.4s;
      text-decoration: none;
      overflow: hidden;
      cursor: pointer;
      border-radius: 3px; /* add rounded corners */
      box-shadow: 0px 4px 4px rgba(0, 0, 0, 0.25);
    }
        
        .button:after {
          content: "";
          background: #f1f1f1;
          display: block;
          position: absolute;
          padding-top: 300%;
          padding-left: 350%;
          margin-left: -20px !important;
          margin-top: -120%;
          opacity: 0;
          transition: all 0.8s
         }


        .button:active:after {
          padding: 0;
          margin: 0;
          opacity: 1;
          transition: 0s
         }

          .row {
            display: flex;
            flex-direction: row;
            flex-wrap: wrap;
          }

          .alignleft {
            display: flex;
            flex-wrap: wrap;
            justify-content: start;
            width: 50%;
          }

          .alignright {
            display: flex;
            flex-wrap: wrap;
            justify-content: end;
            width: 50%;
          }

          .content {
            max-width: 980px;
            margin: auto;
            padding: 0 20px;
          }

          .display-container {
            position: relative;
            overflow: hidden;
          }

          .scrollerbt{
          background-color: #566ef6;
          border: none;
          color: #FFFFFF;
          width: 30px;
          max-width: 500px;
          text-align: center;
          transition-duration: 0.4s;
          text-decoration: none;
          overflow: hidden;
          cursor: pointer;
          border-radius: 3px; /* add rounded corners */
          box-shadow: 0px 4px 4px rgba(0, 0, 0, 0.25);
          padding-left: 10px;
          padding-right: 10px;
        }

        @media (max-width: 940px) {
  .alignleft {
    width: 100%;
  }
  .alignright {
    width: 100%;
    justify-content: left;
  }
  .display-container {
    min-width: auto;
    max-width: 100%;
    justify-content: left;
  }
}

.display-container {
  flex-wrap: wrap;
  min-width: 500px;
  position: relative;
  overflow: hidden;
}

.s{
  flex: auto;
  flex-wrap: wrap;
  min-width: 380px;
}


</style>
  </head>
  <title>Smart Tap Website</title>
    <body onload="onConnect();">
    <div id=\"webpage\">
      <h1>Smart Tap</h1>
        <div class="row"> 
          <div class="alignleft">
            <div class="s">
              <p>Temperature: <span id="temp"></span>&deg;C</p>
              <p>Distance: <span id="dist"></span> Cm</p>
              <p>Flow: <span id="flow"></span> ml/m</p>
              <p>TimeOut: <span class="sliderValue" id="myRangeValue"></span> Seconds</p>
              <div class="slidecontainer">
              <input type="range" min="5" max="60" value="30" class="slider" id="myRange" onInput="setTimeout(displaySliderValue, 500)">
              </div>
              <div class="bt">
                <button class="button" onclick="setMaxDist()">Set stand Distance</button>
              </div>
            <p>Max Distance: <span id="Mdist"></span> Cm</p> 
            </div>
          </div>
          <div class="alignright">
              <div class="content display-container">
                <div class="display-container mySlides">
                  <iframe title="Temp" width="500" height="260" style="border: 3px solid #566ef6" src="https://thingspeak.com/channels/2081084/charts/3?bgcolor=%23ffffff&color=%23d62020&dynamic=true&results=60&title=DS18B20&type=line&xaxis=Timestamp&yaxis=Tempature+%28+C+%29"></iframe>
                </div>
                <div class="display-container mySlides">
                  <iframe title="Distance" width="500" height="260" style="border: 3px solid #566ef6" src="https://thingspeak.com/channels/2081084/charts/4?bgcolor=%23ffffff&color=%23d62020&dynamic=true&results=60&title=Distance&type=line&xaxis=Timestamp&yaxis=Distance+%28+CM+%29"></iframe>
                </div>
                <div class="display-container mySlides">
                  <iframe title="Flow" width="500" height="260" style="border: 3px solid #566ef6" src="https://thingspeak.com/channels/2081084/charts/1?bgcolor=%23ffffff&color=%23d62020&dynamic=true&results=60&title=Flow&type=line&xaxis=Timstamp&yaxis=Flow+%28+ML%2FM+%29"></iframe>
              </div>
              <button class="scrollerbt" onclick="plusDivs(-1)">&#10094;</button>
              <button class="scrollerbt" id="buttonpress" onclick="plusDivs(1)">&#10095;</button>
              </div>
            </div>
          </div>
        </div> 
  </div>
<script>
     var slideIndex = 1;
showDivs(slideIndex);

function plusDivs(n) {
  showDivs(slideIndex += n);
}

function showDivs(n) {
  var i;
  var x = document.getElementsByClassName("mySlides");
  if (n > x.length) {slideIndex = 1}
  if (n < 1) {slideIndex = x.length}
  for (i = 0; i < x.length; i++) {
     x[i].style.display = "none";  
  }
  x[slideIndex-1].style.display = "block";  
}
setInterval(function () {
        document.getElementById("buttonpress").click();
    }, 10000);

</script>
<script>
  function onConnect() {
    displaySliderValue(); 
    updateMaxDist();
   }
  
  async function displaySliderValue() {
   try {
    var slider = document.getElementById("myRange")
    output = document.getElementById("myRangeValue")
    output.innerHTML = slider.value

    var sliderValue = slider.value
    fetch("/getSlide?value=" + sliderValue)
    } catch (error) {
       console.error(error);
      }
   }

  function setMaxDist(){
   try {
    fetch('/setMaxDistance', {method: 'GET'} )
    updateMaxDist();
    } catch (error) {
       console.error(error);
      }
   }

  async function updateMaxDist(){
    try {
    const MDistres = await fetch('/getMaxDist', {method: 'GET'} )
    const MDistdata = await MDistres.text();
    console.log(MDistdata);
    document.getElementById('Mdist').innerHTML = MDistdata;
    } catch (error) {
        console.error(error);
      }
    }
</script>
<script>
  async function updateTemp() {
   try {
    const Tempres = await fetch('/getTemp', {method: 'GET'} )
    const Tempdata = await Tempres.text();
    console.log(Tempdata);
    document.getElementById('temp').innerHTML = Tempdata;
    } catch (error) {
        console.error(error);
      }
   }

  async function updateDist() {
   try {
    const Distres = await fetch('/getDist', {method: 'GET'} )
    const Distdata = await Distres.text();
    console.log(Distdata);
    document.getElementById('dist').innerHTML = Distdata;
    } catch (error) {
        console.error(error);
      }
   }
  async function updateFlow() {
   try {
    const Flowres = await fetch('/getFlow', {method: 'GET'} )
    const Flowdata = await Flowres.text();
    console.log(Flowdata);
    document.getElementById('flow').innerHTML = Flowdata;
    } catch (error) {
        console.error(error);
      }
    }
  const updateAllFuncs = () => {
      updateTemp();
      updateDist();   
      updateFlow();
      displaySliderValue(); 
     }
     setInterval(updateAllFuncs, 1000);
</script>
</body>
</html>
)======";