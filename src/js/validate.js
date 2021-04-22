function validate(event) {
  // TODO - write custom validation logic to validate the longitude and latitude
  // values. The latitude value must be a number between -90 and 90; the
  // longitude value must be a number between -180 and 180. If either/both are
  // invalid, show the appropriate error message in the form, and stop the
  // form from being submitted. If both values are valid, allow the form to be
  // submitted.
  //console.log('TODO - validate the longitude, latitude values before submitting');
  let flag = false;
  let lat = document.querySelector("#latitude").value;
  let lon = document.querySelector("#longitude").value;

  lat = parseFloat(lat);
  lon = parseFloat(lon);

  if (
    (lat < -90 || lat > 90 || isNaN(lat)) &&
    (lon < -180 || lon > 180 || isNaN(lon))
  ) {
    document.querySelector("#error-lat-msg").innerText =
      "must be a valid Latitude (-90 to 90)";
    document.querySelector("#error-lon-msg").innerText = "";
    event.preventDefault();
  } else {
    if (lat < -90 || lat > 90 || isNaN(lat)) {
      document.querySelector("#error-lat-msg").innerText =
        "must be a valid Latitude (-90 to 90)";
      event.preventDefault();
    } else {
      document.querySelector("#error-lat-msg").innerText = "";
    }
    if (lon < -180 || lon > 180 || isNaN(lon)) {
      document.querySelector("#error-lon-msg").innerText =
        "must be a valid Longitude (-180 to 180)";
      event.preventDefault();
    } else {
      document.querySelector("#error-lon-msg").innerText = "";
      flag = true;
    }
  }
  return flag;
}

// Wait for the window to load, then set up the submit event handler for the form.
window.onload = function () {
  const form = document.querySelector("form");
  form.onsubmit = validate;
};
