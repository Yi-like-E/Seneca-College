import { Component, OnDestroy, OnInit } from '@angular/core';
import { MusicDataService } from '../music-data.service';

@Component({
  selector: 'app-favourites',
  templateUrl: './favourites.component.html',
  styleUrls: ['./favourites.component.css']
})
export class FavouritesComponent implements OnInit, OnDestroy {

  favourites: any[] = [];
  favouritesSub: any;
  unfavouritesSub: any;

  constructor(private musicDataService: MusicDataService) { }

  ngOnInit(): void {
    this.favouritesSub = this.musicDataService.getFavourites().subscribe(data => {
      return this.favourites = data.tracks;
    });
  }

  removeFromFavourites(id:any){
    this.unfavouritesSub = this.musicDataService.removeFromFavourites(id).subscribe(data => {
      return this.favourites = data.tracks;
    })
  }
  
  ngOnDestroy(): void {
    this.favouritesSub?.unsubscribe();
    this.unfavouritesSub?.unsubscribe();
  }
}
