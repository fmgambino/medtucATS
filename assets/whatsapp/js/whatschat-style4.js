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


( function( window ) {

    'use strict';

    // class helper functions from bonzo https://github.com/ded/bonzo

    function classReg( className ) {
      return new RegExp("(^|\\s+)" + className + "(\\s+|$)");
    }

    // classList support for class management
    // altho to be fair, the api sucks because it won't accept multiple classes at once
    var hasClass, addClass, removeClass;

    if ( 'classList' in document.documentElement ) {
      hasClass = function( elem, c ) {
        return elem.classList.contains( c );
      };
      addClass = function( elem, c ) {
        elem.classList.add( c );
      };
      removeClass = function( elem, c ) {
        elem.classList.remove( c );
      };
    }
    else {
      hasClass = function( elem, c ) {
        return classReg( c ).test( elem.className );
      };
      addClass = function( elem, c ) {
        if ( !hasClass( elem, c ) ) {
          elem.className = elem.className + ' ' + c;
        }
      };
      removeClass = function( elem, c ) {
        elem.className = elem.className.replace( classReg( c ), ' ' );
      };
    }

    function toggleClass( elem, c ) {
      var fn = hasClass( elem, c ) ? removeClass : addClass;
      fn( elem, c );
    }

    var classie = {
      // full names
      hasClass: hasClass,
      addClass: addClass,
      removeClass: removeClass,
      toggleClass: toggleClass,
      // short names
      has: hasClass,
      add: addClass,
      remove: removeClass,
      toggle: toggleClass
    };

    // transport
    if ( typeof define === 'function' && define.amd ) {
        // AMD
        define( classie );
    } else {
        // browser global
        window.classie = classie;
    }
    
  })( window );


  var ModalEffects = (function() {

    function init() {

      var overlay = document.querySelector( '.wc-overlay' );

      [].slice.call( document.querySelectorAll( '.wc-trigger' ) ).forEach( function( el, i ) {

      var modal = document.querySelector( '#' + el.getAttribute( 'data-modal' ) ),
          close = modal.querySelector( '.wc-close' );

      function removeModal( hasPerspective ){
          classie.remove( modal, 'wc-show' );

          if( hasPerspective ) {
              classie.remove( document.documentElement, 'wc-perspective' );
          }
      }

      function removeModalHandler() {
          removeModal( classie.has( el, 'wc-setperspective' ) ); 
      }

      el.addEventListener( 'click', function( ev ) {
          classie.add( modal, 'wc-show' );
          overlay.removeEventListener( 'click', removeModalHandler );
          overlay.addEventListener( 'click', removeModalHandler );

          if( classie.has( el, 'wc-setperspective' ) ) {
              setTimeout( function() {
                classie.add( document.documentElement, 'wc-perspective' );
              }, 25 );
          }
      });

      close.addEventListener( 'click', function( ev ) {
          ev.stopPropagation();
          removeModalHandler();
      });
    });
  }

  init();

})();