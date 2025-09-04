/*======================================================

Project: WhatsChat - WhatsApp Chat Widget jQuery Plugin
Author: Black Theme
Released On: 27, july 2019
@version: 1.0

========================================================*/

$(document).ready(function(){

    //click event on a tag
    $('.wc-list').on("click",function(){
     
        var number =  $(this).attr("number");
        var message =  $(this).attr("message");
      
        //checking for device type
        if( /Android|webOS|iPhone|iPad|iPod|BlackBerry|IEMobile|Opera Mini/i.test(navigator.userAgent)) {
            // redirect link for mobile WhatsApp chat awc
            window.open('https://wa.me/'+number+'/?text='+message, '-blank');  
        }
        else{
            // redirect link for WhatsApp chat in website
            window.open('https://web.WhatsApp.com/send?phone='+number+'&text='+message, '-blank'); 
        }
    })
});

// to change fa icon of floating chat button
$(function() { 
    $("#wc-times").hide();
    $("#wc-whatsapp").click(function() {
        $("#wc-whatsapp").hide();
        $("#wc-times").fadeIn();
        $(".wc-panel").removeClass("animated bounceOutRight");
        $(".wc-panel").addClass("animated bounceInRight");
        $(".wc-panel").show();
    });

    $("#wc-times").click(function() {
        $("#wc-times").hide();
        $("#wc-whatsapp").fadeIn();
        $(".wc-panel").removeClass("animated bounceInRight");               
        $(".wc-panel").addClass("animated bounceOutRight");
        //$(".wc-panel").hide();
    });
});

