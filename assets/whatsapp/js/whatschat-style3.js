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


    /* WhatsChat Sidebar Function */
    $('.wc-button').click (function(event){
        
        event.preventDefault();
        
        if( $ (this).hasClass('inOut') ){
            $('.wc-style3').stop().animate({right:'-280px'},500 );

        }else{
            $('.wc-style3').stop().animate({right:'0px'},500 );
        } 

        $(this).toggleClass('inOut');

        return false;

    });
});

